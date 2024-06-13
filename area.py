def calculate_area(base, height):
  """Calculates the area of a triangle.

  Args:
      base: The length of the triangle's base.
      height: The length of the triangle's height.

  Returns:
      The area of the triangle.
  """

  area = 0.5 * base * height
  return area

# Get base and height from the user
base = float(input("Enter the base of the triangle: "))
height = float(input("Enter the height of the triangle: "))

# Calculate and print the area
area = calculate_area(base, height)
print("The area of the triangle is:", area)
