

def resolve_line(line):
    c1, c2 = '0', '0'

    for char in line:
        if char.isdigit():
            c1 = char
            break

    for char in reversed(line):
        if char.isdigit():
            c2 = char
            break

    return int(c1 + c2)

def read_stars(file_name):
    calibration_sum = 0
    try:
        with open(file_name, 'r') as file:
            for line in file:
                calibration_sum += resolve_line(line)
    except FileNotFoundError:
        print("Wrong File")
        return 0

    return calibration_sum


if __name__ == "__main__":
    print("Calibration Value is", read_stars("../../files/stars.txt"))