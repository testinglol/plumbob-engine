
void __thiscall
FUN_005fb5aa(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 == (int *)0x0) {
    *param_4 = 0;
    *param_3 = 0;
    local_8 = 0;
    param_4 = param_2;
  }
  else {
    (**(code **)(*piVar1 + 0x24))(piVar1,&local_10);
    *param_2 = local_10;
    *param_3 = local_c;
  }
  *param_4 = local_8;
  return;
}

