
undefined4 * FUN_00606128(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar4;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00604cd2();
  *(undefined1 *)(extraout_ECX + 0x57) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_00673ce8;
  extraout_ECX[0x61] = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_00605816(unaff_EBP + -0x18);
  _memset(extraout_ECX + 3,0,0x6c);
  extraout_ECX[3] = 0x6c;
  puVar4 = extraout_ECX + 0x1e;
  _memset(puVar4,0,0x7c);
  piVar1 = *(int **)(unaff_EBP + 8);
  *puVar4 = 0x7c;
  (**(code **)(*piVar1 + 0x58))(piVar1,puVar4);
  extraout_ECX[0x5c] = extraout_ECX[0x21];
  extraout_ECX[0x5d] = extraout_ECX[0x20];
  if ((*(byte *)((int)extraout_ECX + 0xe1) & 0x40) == 0) {
    *(undefined1 *)((int)extraout_ECX + 0x15d) = 0;
  }
  else {
    *(undefined1 *)((int)extraout_ECX + 0x15d) = 1;
  }
  extraout_ECX[2] = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    iVar2 = (*(code *)**(undefined4 **)extraout_ECX[2])
                      ((undefined4 *)extraout_ECX[2],&DAT_00677308,extraout_ECX + 1);
    if ((-1 < iVar2) && (piVar1 = (int *)extraout_ECX[1], piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0x58))(piVar1,extraout_ECX + 3);
    }
  }
  puVar4 = extraout_ECX + 0x30;
  uVar3 = FUN_005de91d(extraout_ECX + 3);
  FUN_006058b3(uVar3,puVar4);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x57) = 1;
  return extraout_ECX;
}

