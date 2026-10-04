
undefined4 FUN_005dfa0d(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 uVar6;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(int *)(unaff_EBP + 8) != 0) && (*(char *)(extraout_ECX + 4) == '\0')) {
    _memset((void *)(unaff_EBP + -0x90),0,0x7c);
    *(undefined4 *)(unaff_EBP + -0x90) = 0x7c;
    piVar2 = *(int **)(unaff_EBP + 8);
    iVar3 = (**(code **)(*piVar2 + 0x58))(piVar2,unaff_EBP + -0x90);
    if (-1 < iVar3) {
      *(undefined4 *)(extraout_ECX + 0x1c) = *(undefined4 *)(unaff_EBP + -0x84);
      *(undefined4 *)(extraout_ECX + 0x20) = *(undefined4 *)(unaff_EBP + -0x88);
      *(undefined4 *)(extraout_ECX + 0x14) = 0;
      *(undefined4 *)(extraout_ECX + 0x18) = 0;
      puVar4 = (undefined4 *)FUN_005de9cc(unaff_EBP + -0x90);
      bVar1 = *(byte *)(unaff_EBP + -0x27);
      *(undefined4 *)(extraout_ECX + 8) = *puVar4;
      *(undefined4 *)(extraout_ECX + 0xc) = puVar4[1];
      *(undefined4 *)(extraout_ECX + 0x10) = 0;
      if ((bVar1 & 0x40) == 0) {
        *(undefined4 *)(extraout_ECX + 0x40) = 0;
      }
      else {
        *(undefined4 *)(extraout_ECX + 0x40) = 1;
      }
      if ((*(byte *)(unaff_EBP + -0x26) & 2) == 0) {
        if ((*(byte *)(unaff_EBP + -0x27) & 0x10) == 0) {
          *(undefined4 *)(extraout_ECX + 0x44) = 0;
        }
        else {
          *(undefined4 *)(extraout_ECX + 0x44) = 1;
        }
      }
      else {
        *(undefined4 *)(extraout_ECX + 0x44) = 2;
      }
      pvVar5 = operator_new(0x188);
      *(void **)(unaff_EBP + 8) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar5 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_00606128(piVar2);
      }
      *(int *)(extraout_ECX + 0x48) = iVar3;
      if (iVar3 != 0) {
        *(undefined1 *)(extraout_ECX + 4) = 1;
        uVar6 = 1;
        goto LAB_005dfb02;
      }
    }
  }
  uVar6 = 0;
LAB_005dfb02:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

