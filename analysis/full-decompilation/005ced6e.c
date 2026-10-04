
undefined4 __thiscall FUN_005ced6e(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  _memset(&local_54,0,0x50);
  piVar1 = *(int **)(param_1 + 0x1cc);
  local_54 = 0x50;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,&local_54);
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    local_50 = *param_2;
    uStack_4c = param_2[1];
    uStack_48 = param_2[2];
    uStack_44 = param_2[3];
    uVar2 = (**(code **)(**(int **)(param_1 + 0x1cc) + 0xc))(*(int **)(param_1 + 0x1cc),&local_54);
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
  }
  return 0;
}

