
undefined4 __thiscall FUN_004a1c36(int *param_1,short *param_2)

{
  int *piVar1;
  ushort uVar2;
  undefined4 uVar3;
  int *local_c;
  undefined4 local_8;
  
  uVar3 = 0;
  piVar1 = *(int **)*param_1;
  if (piVar1 != (int *)*param_1) {
    local_8 = piVar1[2];
    local_c = param_1;
    FUN_00580b0a(&local_c,piVar1);
    *param_2 = (short)local_8;
    uVar2 = (short)local_8 + 1;
    local_8 = CONCAT22(local_8._2_2_,uVar2);
    if (uVar2 <= local_8._2_2_) {
      FUN_00580875(&local_8);
    }
    uVar3 = 1;
  }
  return uVar3;
}

