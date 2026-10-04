
undefined1 FUN_004c2711(void)

{
  int unaff_EBP;
  int unaff_ESI;
  
  if (*(char *)(unaff_EBP + -0x11) != '\0') {
    *(int *)(unaff_ESI + 0x148) = *(int *)(unaff_ESI + 0x148) + 1;
    *(undefined4 *)(unaff_ESI + 0x144) = DAT_006e5490;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0x11);
}

