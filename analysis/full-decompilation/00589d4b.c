
undefined4 __fastcall FUN_00589d4b(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  iVar1 = param_1[0x62];
  if (iVar1 == -1) {
LAB_00589e24:
    local_8 = 2;
  }
  else {
    if (iVar1 != 0) {
      if (iVar1 == 1) goto LAB_00589e24;
      if (iVar1 == 2) {
        local_8 = 1;
        FUN_005920ac();
        local_10 = __ftol();
        local_14 = __ftol();
        FUN_0048329c(&local_14,0xffffffff);
        piVar2 = (int *)param_1[0x4e];
        local_c = piVar2[0x44];
        iVar1 = piVar2[0x3e];
        iVar3 = piVar2[0x3d];
        cVar4 = (**(code **)(*piVar2 + 0x54))(&local_14,local_c,0,0);
        if (cVar4 == '\0') {
          local_14 = iVar3;
          local_10 = iVar1;
          (**(code **)(*param_1 + 0x20))(1);
          local_8 = 0;
        }
        (**(code **)(*(int *)param_1[0x4e] + 0x88))(&local_14,local_c,0,0);
        return local_8;
      }
    }
    local_8 = 0;
  }
  return local_8;
}

