
void __thiscall FUN_004231a8(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = param_1;
  if ((int *)param_1[100] == (int *)0x0) {
    for (; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[99]) {
      FUN_00431c90(param_2);
    }
    (**(code **)(*param_1 + 0x88))();
    for (; param_1 != (int *)0x0; param_1 = (int *)param_1[99]) {
      FUN_00422d79(0,0,0);
      if ((short)param_2 != 0) {
        (**(code **)(*param_1 + 0x14))(0);
      }
      FUN_0044582f((int)(short)param_1[0x3c],2,*(short *)((int)param_1 + 0xc2) != 0);
      iVar2 = param_1[0x3c];
      uVar3 = FUN_004359a1();
      FUN_0044582f((int)(short)iVar2,8,uVar3);
    }
  }
  else {
    (**(code **)(*(int *)param_1[100] + 0x40))(param_2);
  }
  return;
}

