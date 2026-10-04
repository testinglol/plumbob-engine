
int __thiscall FUN_004485c2(int *param_1,int *param_2)

{
  int *piVar1;
  int extraout_ECX;
  int iVar2;
  undefined1 local_24 [8];
  undefined4 local_1c;
  int local_18 [2];
  undefined1 local_10;
  int local_c;
  int local_8;
  
  FUN_004498b2(&local_8,param_2);
  local_c = *param_1;
  iVar2 = extraout_ECX;
  if (local_8 != local_c) {
    local_10 = (undefined1)param_1[2];
    iVar2 = local_8;
    if (*(int *)(local_8 + 0x10) <= *param_2) goto LAB_0044864d;
  }
  local_1c = 0;
  local_18[0] = *param_2;
  local_18[1] = 0;
  piVar1 = local_18;
  FUN_00448a8d(&local_8);
  piVar1 = (int *)FUN_0044896f(local_24,iVar2,piVar1);
  local_8 = *piVar1;
LAB_0044864d:
  return local_8 + 0x14;
}

