
bool __thiscall
FUN_005fb811(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x18) = param_3;
    *(undefined4 *)(param_1 + 0x1c) = param_4;
    *(undefined4 *)(param_1 + 0x20) = param_8;
    *(undefined4 *)(param_1 + 0x24) = param_9;
    *(undefined4 *)(param_1 + 0x28) = param_10;
    *(undefined4 *)(param_1 + 0x14) = param_2;
    *(undefined4 *)(param_1 + 0x2c) = param_11;
    *(undefined4 *)(param_1 + 0x30) = param_12;
    *(undefined4 *)(param_1 + 0x34) = param_13;
    bVar3 = true;
  }
  else {
    (**(code **)(*piVar1 + 0x38))(piVar1,param_2,param_3,param_4,1);
    (**(code **)(**(int **)(param_1 + 0x38) + 0x40))
              (*(int **)(param_1 + 0x38),param_5,param_6,param_7,1);
    (**(code **)(**(int **)(param_1 + 0x38) + 0x34))
              (*(int **)(param_1 + 0x38),param_8,param_9,param_10,param_11,param_12,param_13,1);
    iVar2 = (**(code **)(**(int **)(param_1 + 0x38) + 0x44))(*(int **)(param_1 + 0x38));
    bVar3 = iVar2 == 0;
  }
  return bVar3;
}

