import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# ... (keep the read_input function unchanged)
def read_input():
    lines = sys.stdin.read().split()
    idx = 0

    # Read center P of Polygon A
    center_a = np.array([float(lines[idx]), float(lines[idx + 1])])
    idx += 2

    # Read number of vertices n of Polygon A
    n = int(lines[idx])
    idx += 1

    # Read vertices of Polygon A
    polygon_a_vertices = []
    for _ in range(n):
        x = float(lines[idx])
        y = float(lines[idx + 1])
        polygon_a_vertices.append([x, y])
        idx += 2
    polygon_a_vertices = np.array(polygon_a_vertices)

    # Read center Q of Polygon B
    center_b = np.array([float(lines[idx]), float(lines[idx + 1])])
    idx += 2

    # Read number of vertices m of Polygon B
    m = int(lines[idx])
    idx += 1

    # Read vertices of Polygon B
    polygon_b_vertices = []
    for _ in range(m):
        x = float(lines[idx])
        y = float(lines[idx + 1])
        polygon_b_vertices.append([x, y])
        idx += 2
    polygon_b_vertices = np.array(polygon_b_vertices)

    return center_a, polygon_a_vertices, center_b, polygon_b_vertices


def rotate_polygon(vertices, center, angle):
    """Rotate polygon vertices around a center point by a given angle."""
    rotation_matrix = np.array([
        [np.cos(angle), -np.sin(angle)],
        [np.sin(angle), np.cos(angle)]
    ])
    return np.dot(vertices - center, rotation_matrix.T) + center

def main():
    # Read input according to the specified format
    center_a, polygon_a_vertices, center_b, polygon_b_vertices = read_input()

    # Setup the plot
    fig, ax = plt.subplots()
    ax.set_aspect('equal')

    # Adjust the plot limits
    all_vertices = np.vstack((polygon_a_vertices, polygon_b_vertices))
    x_min, x_max = np.min(all_vertices[:, 0]) - 5, np.max(all_vertices[:, 0]) + 5
    y_min, y_max = np.min(all_vertices[:, 1]) - 5, np.max(all_vertices[:, 1]) + 5
    ax.set_xlim(x_min, x_max)
    ax.set_ylim(y_min, y_max)

    # Plot Polygon A
    polygon_a_patch = plt.Polygon(polygon_a_vertices, closed=True, fill=None, edgecolor='blue', label='Polygon A')
    ax.add_patch(polygon_a_patch)
    # Plot center of Polygon A
    ax.plot(center_a[0], center_a[1], 'bo')

    # Plot initial Polygon B
    polygon_b_patch = plt.Polygon(polygon_b_vertices, closed=True, fill=None, edgecolor='red', label='Polygon B')
    ax.add_patch(polygon_b_patch)
    # Plot center of Polygon B
    ax.plot(center_b[0], center_b[1], 'ro')

    # Animation function
    def animate(i):
        angle_a = np.radians(-i)  # Negative angle for clockwise rotation of Polygon A
        angle_b = np.radians(-i)  # Negative angle for clockwise rotation of Polygon B
        
        # Rotate Polygon A around its center
        rotated_vertices_a = rotate_polygon(polygon_a_vertices, center_a, angle_a)
        polygon_a_patch.set_xy(rotated_vertices_a)
        
        # Rotate Polygon B around its center
        rotated_vertices_b = rotate_polygon(polygon_b_vertices, center_b, angle_b)
        polygon_b_patch.set_xy(rotated_vertices_b)
        
        return polygon_a_patch, polygon_b_patch

    # Animate both polygons rotating around their centers
    ani = animation.FuncAnimation(
        fig, animate, frames=360, interval=20, blit=True, repeat=True
    )

    plt.legend()
    plt.show()

if __name__ == '__main__':
    main()