
bool __thiscall FUN_005fb553(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 == (int *)0x0) {
    bVar3 = true;
  }
  else {
    (**(code **)(*piVar1 + 0x38))(piVar1,param_2,param_3,param_4,0);
    iVar2 = (**(code **)(**(int **)(param_1 + 0x38) + 0x44))(*(int **)(param_1 + 0x38));
    bVar3 = iVar2 == 0;
  }
  return bVar3;
}

