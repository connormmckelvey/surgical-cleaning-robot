import cv2
from PIL import Image


BOARD_SIZE_MM = 100
SQUARES_X = 3
SQUARES_Y = 3

SQUARE_SIZE_MM = BOARD_SIZE_MM / SQUARES_X  # 20 mm
MARKER_SIZE_MM = SQUARE_SIZE_MM * 0.8  # 16 mm

DPI = 300
OUTPUT_PNG = "charuco_board_100mm.png"
OUTPUT_PDF = "charuco_board_100mm.pdf"


def mm_to_pixels(mm, dpi):
    return round(mm / 25.4 * dpi)


def generate_charuco_board():
    board_size_px = mm_to_pixels(BOARD_SIZE_MM, DPI)

    dictionary = cv2.aruco.getPredefinedDictionary(
        cv2.aruco.DICT_5X5_50
    )

    board = cv2.aruco.CharucoBoard(
        (SQUARES_X, SQUARES_Y),
        SQUARE_SIZE_MM,
        MARKER_SIZE_MM,
        dictionary
    )

    board_image = board.generateImage(
        (board_size_px, board_size_px),
        marginSize=0,
        borderBits=1
    )

    image = Image.fromarray(board_image)

    image.save(
        OUTPUT_PNG,
        dpi=(DPI, DPI)
    )

    image.convert("RGB").save(
        OUTPUT_PDF,
        "PDF",
        resolution=DPI
    )

    print(f"Generated: {OUTPUT_PNG}")
    print(f"Generated: {OUTPUT_PDF}")
    print()
    print(f"Board size: {BOARD_SIZE_MM} mm x {BOARD_SIZE_MM} mm")
    print(f"Squares: {SQUARES_X} x {SQUARES_Y}")
    print(f"Square size: {SQUARE_SIZE_MM} mm")
    print(f"Marker size: {MARKER_SIZE_MM} mm")
    print("Dictionary: DICT_5X5_50")
    print(f"Resolution: {board_size_px} x {board_size_px} pixels")


if __name__ == "__main__":
    generate_charuco_board()