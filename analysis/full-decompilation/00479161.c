
undefined4 * __thiscall FUN_00479161(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_18;
  int local_14;
  char local_10;
  char local_f;
  undefined1 local_e;
  char local_c;
  char local_b;
  undefined1 local_a;
  char local_8;
  char local_7;
  undefined1 local_6;
  
  FUN_0047795a(param_2);
  param_1[0x21] = 0;
  local_c = '\0';
  local_b = '\0';
  local_a = 0;
  local_10 = *(char *)(param_1 + 4) + -1;
  local_7 = '\0';
  local_6 = 0;
  local_e = 0;
  *param_1 = &PTR_FUN_00667a94;
  param_2 = (uint)(CONCAT21((short)((uint)param_2 >> 0x10),local_10) & 0xff00ff) << 8;
  local_f = local_10;
  local_8 = local_10;
  FUN_00434ffd(0);
  FUN_00434ffd(param_1[0x21]);
  FUN_00434ffd(param_1[0x21]);
  FUN_00434ffd(param_1[0x21]);
  iVar3 = (int)local_8;
  local_14 = (int)local_c;
  local_18 = iVar3;
  piVar2 = &local_18;
  if (local_14 <= iVar3) {
    piVar2 = &local_14;
  }
  iVar4 = (int)local_10;
  piVar1 = param_1 + 0x1c;
  *piVar1 = *piVar2;
  local_18 = iVar4;
  piVar2 = &local_18;
  if (*piVar1 <= iVar4) {
    piVar2 = piVar1;
  }
  *piVar1 = *piVar2;
  local_18 = (int)(char)param_2;
  piVar2 = &local_18;
  if (*piVar1 <= (int)(char)param_2) {
    piVar2 = piVar1;
  }
  *piVar1 = *piVar2;
  local_18 = iVar3;
  piVar2 = &local_18;
  if (iVar3 <= local_14) {
    piVar2 = &local_14;
  }
  piVar1 = param_1 + 0x1d;
  *piVar1 = *piVar2;
  local_18 = iVar4;
  piVar2 = &local_18;
  if (iVar4 <= *piVar1) {
    piVar2 = piVar1;
  }
  *piVar1 = *piVar2;
  local_18 = (int)(char)param_2;
  piVar2 = &local_18;
  if ((int)(char)param_2 <= *piVar1) {
    piVar2 = piVar1;
  }
  iVar3 = (int)local_7;
  local_14 = (int)local_b;
  *piVar1 = *piVar2;
  local_18 = iVar3;
  piVar2 = &local_18;
  if (local_14 <= iVar3) {
    piVar2 = &local_14;
  }
  iVar4 = (int)local_f;
  piVar1 = param_1 + 0x1e;
  *piVar1 = *piVar2;
  local_18 = iVar4;
  piVar2 = &local_18;
  if (*piVar1 <= iVar4) {
    piVar2 = piVar1;
  }
  *piVar1 = *piVar2;
  local_18 = (int)param_2._1_1_;
  piVar2 = &local_18;
  if (*piVar1 <= (int)param_2._1_1_) {
    piVar2 = piVar1;
  }
  *piVar1 = *piVar2;
  local_18 = iVar3;
  piVar2 = &local_18;
  if (iVar3 <= local_14) {
    piVar2 = &local_14;
  }
  piVar1 = param_1 + 0x1f;
  *piVar1 = *piVar2;
  local_18 = iVar4;
  piVar2 = &local_18;
  if (iVar4 <= *piVar1) {
    piVar2 = piVar1;
  }
  *piVar1 = *piVar2;
  param_2 = (int)param_2._1_1_;
  piVar2 = &param_2;
  if (param_2 <= *piVar1) {
    piVar2 = piVar1;
  }
  *piVar1 = *piVar2;
  return param_1;
}

