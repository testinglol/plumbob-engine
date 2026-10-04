
void __thiscall
FUN_005fac33(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(char *)(param_1 + 0x2c) == '\0') {
    *param_2 = *(undefined4 *)(param_1 + 0x38);
    *param_3 = *(undefined4 *)(param_1 + 0x3c);
    local_8 = *(undefined4 *)(param_1 + 0x40);
  }
  else {
    piVar1 = *(int **)(param_1 + 4);
    if (piVar1 == (int *)0x0) {
      return;
    }
    (**(code **)(*piVar1 + 0x28))(piVar1,&local_10);
    *param_2 = local_10;
    *param_3 = local_c;
  }
  *param_4 = local_8;
  return;
}

