
void __thiscall
FUN_005fb520(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,&local_10);
    *param_2 = local_10;
    *param_3 = local_c;
    *param_4 = local_8;
  }
  return;
}

