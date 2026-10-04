
void __thiscall
FUN_005fb629(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6,undefined4 *param_7)

{
  int *piVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 == (int *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x20);
    *param_3 = *(undefined4 *)(param_1 + 0x24);
    *param_4 = *(undefined4 *)(param_1 + 0x28);
    *param_5 = *(undefined4 *)(param_1 + 0x2c);
    *param_6 = *(undefined4 *)(param_1 + 0x30);
    local_14 = *(undefined4 *)(param_1 + 0x34);
  }
  else {
    (**(code **)(*piVar1 + 0x18))(piVar1,&local_10,&local_1c);
    *param_2 = local_10;
    *param_3 = local_c;
    *param_4 = local_8;
    *param_5 = local_1c;
    *param_6 = local_18;
  }
  *param_7 = local_14;
  return;
}

