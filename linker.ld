
ENTRY(_start)

SECTIONS
{
  . = 0x00000000000016a0;

  .text : {
    *(.text)
  }

  .data : {
    *(.data)
  }

  .bss : {
    *(.bss)
  }
}
