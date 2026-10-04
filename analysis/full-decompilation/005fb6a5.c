
bool __thiscall
FUN_005fb6a5(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x20) = param_2;
    *(undefined4 *)(param_1 + 0x24) = param_3;
    *(undefined4 *)(param_1 + 0x28) = param_4;
    *(undefined4 *)(param_1 + 0x2c) = param_5;
    *(undefined4 *)(param_1 + 0x30) = param_6;
    *(undefined4 *)(param_1 + 0x34) = param_7;
    bVar3 = true;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x34))(piVar1,param_2,param_3,param_4,param_5,param_6,param_7,1);
    bVar3 = iVar2 == 0;
  }
  return bVar3;
}

