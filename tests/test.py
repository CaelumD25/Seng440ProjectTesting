import subprocess
import time
import sys

def run_and_time_binary(binary_path, expected_output):
    # Start timing
    start_time = time.time()

    try:
        # Run the binary and capture the output
        result = subprocess.run([binary_path], capture_output=True, text=True, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Error running the binary: {e}")
        return False

    # Stop timing
    end_time = time.time()
    elapsed_time = end_time - start_time

    # Get the output from the binary
    output = result.stdout.strip()

    # Verify the output
    if output == expected_output:
        print(f"Output is correct: {output}")
    else:
        print(f"Output is incorrect: {output}")
        print(f"Expected output: {expected_output}")

    print(f"Execution time: {elapsed_time:.6f} seconds")

    return output == expected_output

if __name__ == "__main__":
    binary_path = "./main"  # Path to the C binary
    expected_output = " ".join(sys.argv[1:])  # The expected output from the binary

    if run_and_time_binary(binary_path, expected_output):
        print("Test passed.")
    else:
        print("Test failed.")
        exit(1)