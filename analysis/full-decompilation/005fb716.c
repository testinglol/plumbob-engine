
void __thiscall
FUN_005fb716(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8,
            undefined4 *param_9,undefined4 *param_10,undefined4 *param_11,undefined4 *param_12,
            undefined4 *param_13)

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
    *param_2 = *(undefined4 *)(param_1 + 0x14);
    *param_3 = *(undefined4 *)(param_1 + 0x18);
    *param_4 = *(undefined4 *)(param_1 + 0x1c);
    *param_5 = 0;
    *param_6 = 0;
    *param_7 = 0;
    *param_8 = *(undefined4 *)(param_1 + 0x20);
    *param_9 = *(undefined4 *)(param_1 + 0x24);
    *param_10 = *(undefined4 *)(param_1 + 0x28);
    *param_11 = *(undefined4 *)(param_1 + 0x2c);
    *param_12 = *(undefined4 *)(param_1 + 0x30);
    local_14 = *(undefined4 *)(param_1 + 0x34);
  }
  else {
    (**(code **)(*piVar1 + 0x1c))(piVar1,&local_10);
    *param_2 = local_10;
    *param_3 = local_c;
    *param_4 = local_8;
    (**(code **)(**(int **)(param_1 + 0x38) + 0x24))(*(int **)(param_1 + 0x38),&local_10);
    *param_5 = local_10;
    *param_6 = local_c;
    *param_7 = local_8;
    (**(code **)(**(int **)(param_1 + 0x38) + 0x18))(*(int **)(param_1 + 0x38),&local_10,&local_1c);
    *param_8 = local_10;
    *param_9 = local_c;
    *param_10 = local_8;
    *param_11 = local_1c;
    *param_12 = local_18;
  }
  *param_13 = local_14;
  return;
}

