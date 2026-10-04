
undefined1 __thiscall FUN_0057e191(int *param_1,int param_2,int param_3,char param_4)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  *(bool *)(param_1 + 0x73) = param_3 == 0;
  *(bool *)((int)param_1 + 0x1cd) = 0 < param_3;
  *(bool *)((int)param_1 + 0x1ce) = param_3 < 0;
  uVar1 = FUN_005805fa(param_2,param_3);
  if (param_4 != '\0') {
    return uVar1;
  }
  if (param_2 < 0x23) {
    if (param_2 == 0x22) {
      if ((int *)param_1[0x74] == (int *)0x0) {
        return 1;
      }
      (**(code **)(*(int *)param_1[0x74] + 0xb4))(param_3);
      return 1;
    }
    if (param_2 < 0x1d) {
      if (param_2 == 0x1c) {
        iVar3 = (**(code **)(*param_1 + 0x88))(0x1a);
        if (iVar3 == 0) {
          return 1;
        }
        iVar3 = *(int *)param_1[0x74];
        uVar4 = (**(code **)(*param_1 + 0x88))(0x1c);
        (**(code **)(iVar3 + 0xa4))(uVar4);
        return 1;
      }
      if (param_2 < 0x12) {
        return 1;
      }
      if (0x14 < param_2) {
        if (param_2 == 0x15) goto LAB_0057e349;
        if (param_2 != 0x1b) {
          return 1;
        }
      }
    }
    else {
      if (param_2 == 0x1d) {
        iVar3 = (**(code **)(*param_1 + 0x88))(0x1a);
        if (iVar3 == 0) {
          return 1;
        }
        iVar3 = *(int *)param_1[0x74];
        uVar4 = (**(code **)(*param_1 + 0x88))(0x1d);
        (**(code **)(iVar3 + 0xa8))(uVar4);
        return 1;
      }
      if (param_2 < 0x1e) {
        return 1;
      }
      if (0x20 < param_2) {
        if (param_2 != 0x21) {
          return 1;
        }
        if ((int *)param_1[0x74] == (int *)0x0) {
          return 1;
        }
        (**(code **)(*(int *)param_1[0x74] + 0xac))(param_3);
        return 1;
      }
    }
  }
  else {
    if (param_2 == 0x23) {
      if ((int *)param_1[0x74] == (int *)0x0) {
        return 1;
      }
      (**(code **)(*(int *)param_1[0x74] + 0xb0))(param_3);
      return 1;
    }
    if (param_2 == 0x2d) {
      cVar2 = (**(code **)(*param_1 + 0x70))();
      if (cVar2 != '\0') {
        return 1;
      }
      param_1[0x2a] = 0;
      return 1;
    }
    if (param_2 == 0x32) {
      cVar2 = FUN_0057f91e(param_1[0x3a]);
      if (cVar2 == '\0') {
        return 0;
      }
      FUN_0057fa52();
LAB_0057e349:
      FUN_0057fa16();
      return 1;
    }
    if (param_2 == 0x35) {
      if (param_3 != 0) {
        iVar3 = FUN_00573466(param_3);
        param_1[0x32] = iVar3;
        return 1;
      }
      param_1[0x32] = (int)param_1;
      return 1;
    }
    if (param_2 < 0x38) {
      return 1;
    }
    if (0x39 < param_2) {
      if (param_2 != 0x7b) {
        return 1;
      }
      FUN_0057d5c4(param_1,param_3);
      return 1;
    }
  }
  FUN_0057fa52();
  return 1;
}

