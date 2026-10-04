
void FUN_00492942(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int iVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(DAT_006e54dc + 0x10);
  *(int *)(unaff_EBP + -0x14) = DAT_006e54dc;
  iVar4 = *(int *)(extraout_ECX + 0x3c);
  *(int *)(unaff_EBP + -0x18) = iVar1;
  if (iVar4 == 0) {
    pvVar2 = operator_new(0x20);
    *(void **)(unaff_EBP + -0x10) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_0047c8fb(0x40);
    }
    *(undefined4 *)(extraout_ECX + 0x3c) = uVar3;
  }
  if (((*(int *)(extraout_ECX + 0x3c) != 0) &&
      (iVar1 <= *(int *)(*(int *)(extraout_ECX + 0x3c) + 8))) &&
     (*(undefined4 *)(unaff_EBP + -0x10) = 0, 0 < iVar1)) {
    do {
      iVar1 = *(int *)(unaff_EBP + -0x10);
      iVar4 = 0;
      do {
        *(byte *)(*(int *)(*(int *)(*(int *)(extraout_ECX + 0x3c) + 0xc) + iVar1 * 4) + iVar4) =
             *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x14) + 0x34) + 0xc) +
                               (char)iVar1 * 4) + (int)(char)iVar4) & 0x20;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(unaff_EBP + -0x18));
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x18));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

