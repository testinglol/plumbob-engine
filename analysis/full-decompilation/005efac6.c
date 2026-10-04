
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_005efac6(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = _memcmp((void *)(extraout_ECX + 0xc4),&DAT_006f2a14,0x10);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(extraout_ECX + 0x2c8))(0,&DAT_006fec9c,0);
  }
  else {
    iVar2 = (**(code **)(extraout_ECX + 0x2c8))((void *)(extraout_ECX + 0xc4),&DAT_006fec9c,0);
  }
  if (iVar2 == 0) {
    iVar2 = (**(code **)*DAT_006fec9c)(DAT_006fec9c,&DAT_00677328,&DAT_006feca0);
    if (iVar2 < 0) {
      *(int *)(unaff_EBP + -0x14) = iVar2;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
      (*(code *)PTR_FUN_00675038)(0);
      iVar2 = *(int *)(unaff_EBP + -0x18);
      *(undefined4 *)(unaff_EBP + -4) = 3;
      goto LAB_005efb3b;
    }
    _memset(&DAT_006feb20,0,0x17c);
    _DAT_006feb20 = 0x17c;
    iVar2 = (**(code **)(*DAT_006fec9c + 0x2c))(DAT_006fec9c,&DAT_006feb20,0);
    if (iVar2 == 0) {
      iVar2 = _memcmp((void *)(extraout_ECX + 0xc4),&DAT_006f2a14,0x10);
      *(char *)(extraout_ECX + 0x98) = '\x01' - (iVar2 != 0);
      uVar3 = CONCAT31((int3)((uint)-iVar2 >> 8),1);
      *(byte *)(extraout_ECX + 0x99) = (byte)(DAT_006feb24 >> 7) & 1;
      goto LAB_005efc33;
    }
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 4;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    *(undefined4 *)(unaff_EBP + -4) = 5;
    (**(code **)(*(int *)(unaff_EBP + -0x18) + 0x10))();
    piVar1 = DAT_006fec9c;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_0067504c;
    uVar3 = (**(code **)(*piVar1 + 8))(piVar1);
    DAT_006fec9c = (int *)0x0;
  }
  else {
    *(int *)(unaff_EBP + -0x14) = iVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_00675034;
    (*(code *)PTR_FUN_00675038)(0);
    iVar2 = *(int *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 1;
LAB_005efb3b:
    uVar3 = (**(code **)(iVar2 + 0x10))();
  }
  uVar3 = uVar3 & 0xffffff00;
LAB_005efc33:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

