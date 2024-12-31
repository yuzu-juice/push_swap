import subprocess
import random
import sys
from typing import List, Tuple
import time

def generate_random_numbers(size: int) -> List[int]:
    """Generate a list of random integers within 32-bit signed range"""
    return [random.randint(-2**31, 2**31 - 1) for _ in range(size)]

def run_push_swap_and_checker(numbers: List[int]) -> Tuple[bool, str, int]:
    """
    Run push_swap and checker with given numbers
    Returns: (success: bool, error_message: str, operation_count: int)
    """
    # Convert numbers to string
    numbers_str = ' '.join(map(str, numbers))

    try:
        # Run push_swap
        push_swap_process = subprocess.Popen(
            ['./push_swap'] + numbers_str.split(),
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )
        push_swap_output, push_swap_error = push_swap_process.communicate()

        if push_swap_process.returncode != 0:
            return False, f"push_swap failed with error: {push_swap_error.decode('utf-8')}", 0

        # Count operations
        operation_count = len(push_swap_output.decode('utf-8').strip().split('\n'))
        if operation_count == 1 and push_swap_output.decode('utf-8').strip() == '':
            operation_count = 0

        # Run checker
        checker_process = subprocess.Popen(
            ['./checker_Mac'] + numbers_str.split(),
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )
        checker_output, checker_error = checker_process.communicate(input=push_swap_output)

        checker_result = checker_output.decode('utf-8').strip()
        if checker_result != "OK":
            return False, f"Checker returned: {checker_result}", operation_count

        return True, "OK", operation_count

    except Exception as e:
        return False, f"Error occurred: {str(e)}", 0

def run_tests(num_tests: int, min_size: int, max_size: int) -> None:
    """
    Run specified number of tests with random array sizes between min_size and max_size
    """
    print(f"Starting tests: {num_tests} iterations with array sizes {min_size}-{max_size}")
    print("-" * 50)

    start_time = time.time()
    failed_cases = []
    total_operations = 0
    max_operations = 0
    max_operations_case = None

    for i in range(num_tests):
        size = random.randint(min_size, max_size)
        numbers = generate_random_numbers(size)

        print(f"Test {i+1}/{num_tests} - Testing with {size} numbers... ", end='', flush=True)

        success, message, operations = run_push_swap_and_checker(numbers)
        print(f"{'✓' if success else '✗'} ({operations} ops)")

        if success:
            total_operations += operations
            if operations > max_operations:
                max_operations = operations
                max_operations_case = numbers.copy()
        else:
            failed_cases.append((numbers, message, operations))
            print(f"Failed case details:\nNumbers: {' '.join(map(str, numbers))}\nError: {message}")
            print("Stopping tests due to failure.")
            break

    end_time = time.time()
    print("-" * 50)
    print("Test summary:")
    print(f"Total tests run: {i+1}")
    print(f"Successful tests: {i+1 - len(failed_cases)}")
    print(f"Failed tests: {len(failed_cases)}")
    print(f"Total time: {end_time - start_time:.2f} seconds")

    if failed_cases:
        print("\nFailed test cases:")
        for i, (numbers, message, operations) in enumerate(failed_cases, 1):
            print(f"\nFailed case {i}:")
            print(f"Numbers: {' '.join(map(str, numbers))}")
            print(f"Error: {message}")
            print(f"Operations: {operations}")
        sys.exit(1)
    else:
        print("\nAll tests passed successfully!")
        print(f"Average operations: {total_operations / num_tests:.2f}")
        print(f"Maximum operations: {max_operations}")

if __name__ == "__main__":
    # Configuration
    NUM_TESTS = 2000  # Number of test cases to run
    MIN_SIZE = 100   # Minimum array size
    MAX_SIZE = 100   # Maximum array size

    # Run the tests
    run_tests(NUM_TESTS, MIN_SIZE, MAX_SIZE)