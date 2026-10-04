
void __fastcall FUN_005d5d01(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  FUN_00473622();
  if (DAT_006d6f9c == '\0') {
    MsgWaitForMultipleObjects(0,(HANDLE *)0x0,0,100,0xff);
  }
  (**(code **)(*(int *)(param_1[4] + 0x48) + 0x24))();
  iVar2 = DAT_006fe8c4;
  uVar1 = DAT_006fe8c0 & 3;
  DAT_006fe8c0 = DAT_006fe8c0 + 1;
  if (uVar1 == 0) {
    DAT_006fe8c4 = DAT_006fe8c4 + 1;
    piVar3 = (int *)(**(code **)(*param_1 + 0x38))();
    (**(code **)(*piVar3 + 0x10))(iVar2);
  }
  puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x1c))();
  (**(code **)*puVar4)();
  FUN_005d52b1();
  return;
}

