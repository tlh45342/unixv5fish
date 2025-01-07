`guestfish` is a versatile shell and command-line tool for examining and modifying virtual machine filesystems. It offers a comprehensive set of commands to manage disk images and filesystems. Here's an overview of some key functionalities:

**Disk and Filesystem Operations:**

- **add**: Add a disk image or device.
- **run**: Initialize and launch the libguestfs backend.
- **list-filesystems**: List detected filesystems within added devices.
- **mount**: Mount a filesystem from the disk image.
- **umount**: Unmount a mounted filesystem.
- **mkfs**: Create a new filesystem on a partition.
- **part-add**: Add a partition to a disk.
- **part-del**: Delete a partition from a disk.

**File Operations:**

- **ls**: List directory contents.
- **cp**: Copy files within the guest filesystem.
- **upload**: Copy files from the host to the guest filesystem.
- **download**: Copy files from the guest to the host filesystem.
- **rm**: Remove files or directories.
- **mkdir**: Create a new directory.
- **rmdir**: Remove an empty directory.
- **edit**: Open a file in the default editor for modification.
- **cat**: Display the contents of a file.

**System Inspection and Information:**

- **inspect-os**: Detect operating systems within the disk image.
- **inspect-get-distro**: Retrieve the detected distribution name.
- **inspect-get-mountpoints**: Get a list of mountpoints for the detected OS.
- **df**: Display disk space usage of mounted filesystems.
- **du**: Estimate file and directory space usage.

**Logical Volume Management (LVM):**

- **lvs**: List logical volumes.
- **vgs**: List volume groups.
- **pvs**: List physical volumes.
- **lvcreate**: Create a new logical volume.
- **lvremove**: Remove a logical volume.
- **lvresize**: Resize a logical volume.

**Advanced Features:**

- **scrub-device**: Securely erase a device.
- **zero**: Zero out a file or device.
- **sparse**: Create a sparse file.
- **tar-in**: Unpack a tarball into the guest filesystem.
- **tar-out**: Pack a directory from the guest into a tarball.

This overview covers some of the primary commands available in `guestfish`. For a comprehensive list and detailed descriptions, you can refer to the official manual page. 

[libguestfs](https://libguestfs.org/guestfish.1.html?utm_source=chatgpt.com)

