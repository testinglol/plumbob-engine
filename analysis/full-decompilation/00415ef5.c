
undefined4 __thiscall FUN_00415ef5(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_8;
  
  uVar4 = param_2;
  uVar1 = *(undefined2 *)(*(int *)(param_1 + 0x20) + 0x38);
  local_8 = param_1;
  iVar2 = FUN_00416912(*(int *)(param_1 + 0x20),param_2,s_IMISSUOH_006c1ef4._0_4_,
                       CONCAT22((short)((uint)&param_2 >> 0x10),DAT_006c1ef0),&param_2);
  if (iVar2 != 0) {
    FUN_00416912(*(undefined4 *)(param_1 + 0x20),uVar4,s_IMISSUOH_006c1ef4._0_4_,0,0);
    param_2 = 0;
  }
  FUN_0046dae0(0x14,uVar1);
  FUN_0046dae0(0x21,*(undefined2 *)(DAT_006e486c + 0x6a));
  FUN_0046dae0(0x20,0);
  iVar2 = (int)*(short *)(*(int *)(param_1 + 0x20) + 0x3e);
  if (iVar2 == 0) {
    iVar2 = 0x40;
  }
  FUN_00415e16(iVar2);
  FUN_005d4bbf(&DAT_006de560);
  FUN_00416969(param_1,uVar4,s_IMISSUOH_006c1ef4._4_4_,
               CONCAT22((short)((uint)&local_8 >> 0x10),DAT_006c1ef2),&local_8);
  FUN_00476bac(0);
  FUN_0046dae0(9,0);
  uVar3 = FUN_00425db3(0);
  *(undefined4 *)(param_1 + 0x10) = uVar3;
  FUN_004427da();
  FUN_0047870b(uVar4,param_2);
  FUN_004a0fb4(uVar4,*(undefined4 *)(param_1 + 0x1c),local_8);
  FUN_004c5f1c(uVar4,*(undefined4 *)(param_1 + 0x1c),local_8);
  FUN_0043fc42(uVar4);
  FUN_0040766a(0x93,uVar4);
  FUN_0040766a(0x83,0);
  FUN_0040766a(0x91,0);
  FUN_0040766a(0xe8,0);
  uVar4 = FUN_0046d9e5();
  FUN_0040766a(0xda,uVar4);
  FUN_0040766a(0xdd,0);
  FUN_0046716c();
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = param_2;
  }
  return 0;
}

