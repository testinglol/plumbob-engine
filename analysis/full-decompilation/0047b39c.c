
undefined4 FUN_0047b39c(void)

{
  short sVar1;
  int unaff_EBP;
  undefined4 uVar2;
  
  FUN_00634c24();
  sVar1 = *(short *)(unaff_EBP + 8);
  if (sVar1 < 0xc1) {
    if (sVar1 == 0xc0) {
      uVar2 = 0;
LAB_0047b3ca:
      FUN_0047caec(uVar2);
      FUN_0040766a(0x83,0);
    }
    else if (sVar1 == 0x91) {
      FUN_00479f0c(*(undefined4 *)(unaff_EBP + 0xc));
    }
    else {
      if (sVar1 == 0xbd) {
        FUN_0047b48b();
      }
      else {
        if (sVar1 != 0xbe) {
          if (sVar1 != 0xbf) goto LAB_0047b42e;
          uVar2 = 4;
          goto LAB_0047b3ca;
        }
        FUN_0047b4b7();
      }
      uVar2 = 0x85;
LAB_0047b3f8:
      FUN_0040766a(uVar2,0);
      FUN_0040766a(0x83,0);
    }
  }
  else if (sVar1 == 0xc1) {
    FUN_0047b50a(0x50);
  }
  else if (sVar1 == 0xf8) {
    if (*(short *)(*(int *)(DAT_006e486c + 0x1c) + 0x58) != 0) {
      FUN_0047b53a(*(undefined4 *)(unaff_EBP + 0xc));
      uVar2 = 0x86;
      goto LAB_0047b3f8;
    }
  }
  else {
    if (sVar1 != 0x106) {
LAB_0047b42e:
      uVar2 = 0;
      goto LAB_0047b47d;
    }
    *(undefined1 *)(unaff_EBP + 10) = 0;
    *(undefined1 *)(unaff_EBP + 8) = *(undefined1 *)(unaff_EBP + 0xc);
    *(undefined1 *)(unaff_EBP + 9) = *(undefined1 *)(unaff_EBP + 0xe);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0047bf93(unaff_EBP + 8);
  }
  uVar2 = 1;
LAB_0047b47d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

