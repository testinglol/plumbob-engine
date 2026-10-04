
int FUN_0053d6da(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(int *)(unaff_EBP + 8) == 0x16) || (*(int *)(unaff_EBP + 8) == 0x17)) {
    puVar2 = *(undefined1 **)(unaff_EBP + 0x10);
    *(undefined1 *)(unaff_EBP + 8) = *puVar2;
    uVar1 = puVar2[2];
    *(undefined1 *)(unaff_EBP + 9) = puVar2[1];
    *(undefined1 *)(unaff_EBP + 10) = uVar1;
    iVar5 = DAT_006e54d8;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00434ffd(-*(int *)(iVar5 + 0x84) & 3);
    if (*(int *)(DAT_006e54d8 + 0x84) == 0) {
      uVar4 = *(undefined4 *)(unaff_EBP + 0x14);
    }
    else {
      uVar4 = *(undefined4 *)
               (&DAT_006f4a20 +
               (*(int *)(unaff_EBP + 0x14) + *(int *)(DAT_006e54d8 + 0x84) * -0x40) * 4);
    }
    puVar3 = *(undefined4 **)(unaff_EBP + 0xc);
    iVar5 = FUN_00435a00(puVar3,unaff_EBP + 8,uVar4);
    if (iVar5 == 0) {
      *puVar3 = 0;
      iVar5 = ((*(int *)(unaff_EBP + 0x1c) != 0) - 0x1fe) + *(int *)(unaff_EBP + 0x18) * 0x200;
    }
    else {
      iVar5 = iVar5 + *(int *)(unaff_EBP + 0x1c) * 3 + -1 + *(int *)(unaff_EBP + 0x18);
    }
  }
  else {
    iVar5 = ((*(int *)(unaff_EBP + 0x1c) != 0) - 0x200) +
            (*(int *)(unaff_EBP + 0x18) * 0x100 + *(int *)(unaff_EBP + 8)) * 2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar5;
}

