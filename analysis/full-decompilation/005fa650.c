
undefined4 __fastcall FUN_005fa650(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  (**(code **)(*param_1 + 0x14))(param_1 + 5,1);
  if (*(int **)param_1[0x2f] != (int *)0x0) {
    (**(code **)(**(int **)param_1[0x2f] + 8))();
    FUN_006321f0(*(undefined4 *)param_1[0x2f]);
    *(undefined4 *)param_1[0x2f] = 0;
  }
  iVar1 = param_1[0x2f];
  uVar2 = *(undefined4 *)(iVar1 + 0xc);
  uVar3 = *(undefined4 *)(iVar1 + 0x10);
  uVar4 = *(undefined4 *)(iVar1 + 0x24);
  FUN_005f98f3();
  *(undefined4 *)(param_1[0x2f] + 0xc) = uVar2;
  *(undefined4 *)(param_1[0x2f] + 0x10) = uVar3;
  *(undefined4 *)(param_1[0x2f] + 0x24) = uVar4;
  *(undefined4 *)(param_1[0x2f] + 0x18) = 0;
  *(undefined4 *)(param_1[0x2f] + 0x28) = 1;
  *(undefined4 *)(param_1[0x2f] + 0x2c) = 1;
  *(undefined4 *)(param_1[0x2f] + 0x30) = 1;
  *(undefined4 *)(param_1[0x2f] + 0x34) = 1;
  DAT_006fed8c = 1;
  FUN_005d4bbf(&DAT_006de560);
  return 1;
}

