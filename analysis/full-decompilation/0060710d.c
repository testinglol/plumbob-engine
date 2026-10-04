
void __thiscall FUN_0060710d(int *param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  int local_14;
  int local_10;
  int local_c;
  char local_5;
  
  (**(code **)(*param_1 + 0x94))();
  if (param_1[0x42] == 0) {
    return;
  }
  FUN_005f53ae();
  FUN_004ed071();
  local_10 = 0;
  local_5 = '\0';
  local_c = *(int *)(*(int *)(param_1[0x46] + 4) + 8);
  if (local_c != *(int *)(param_1[0x46] + 4)) {
    do {
      if (param_2 == (char *)0x0) {
LAB_00607187:
        iVar2 = local_c + 0x10;
        uVar3 = FUN_005f51ce(iVar2);
        FUN_005f51e0(uVar3,iVar2);
        FUN_0042eab4(&local_10);
        if ((param_2 != (char *)0x0) &&
           (iVar2 = _strcmp(param_2,*(char **)(local_c + 0x10)), iVar2 == 0)) {
          local_5 = '\x01';
          iVar2 = FUN_005f51ce();
          local_14 = iVar2 + -1;
        }
      }
      else {
        sVar1 = _strlen(param_2);
        iVar2 = FUN_004558e0(param_2,0,sVar1);
        if (iVar2 != -1) goto LAB_00607187;
      }
      FUN_0041674f();
      local_10 = local_10 + 1;
    } while (local_c != *(int *)(param_1[0x46] + 4));
    if (local_5 != '\0') goto LAB_00607201;
  }
  iVar2 = FUN_005f51ce();
  if (iVar2 == 0) {
    (**(code **)(*(int *)param_1[0x45] + 0x1a0))(s_Sorry__no_cheats_match_the_searc_006d92c8);
    return;
  }
  local_14 = 0;
LAB_00607201:
  FUN_005f5543(local_14);
  return;
}

