
void __thiscall FUN_004d23b5(int param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  SHORT SVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar1 = *(int **)(param_1 + 0x144);
  if (param_2 == '\0') {
    iVar5 = (**(code **)(*piVar1 + 0x1d8))();
    if (iVar5 == -1) goto LAB_004d23df;
    (**(code **)(*piVar1 + 0x1c8))();
    iVar4 = __ftol();
    iVar7 = (**(code **)(*piVar1 + 0x1d0))();
    iVar4 = (iVar4 - iVar7) / 0x2a + 1;
  }
  else {
    iVar5 = -1;
LAB_004d23df:
    iVar4 = 0;
  }
  if (iVar5 == -1) {
    *(undefined4 *)(param_1 + 0x1174) = 0;
    *(undefined4 *)(param_1 + 0x1178) = 0;
  }
  else if (iVar5 == 0) {
    iVar5 = *(int *)(param_1 + 0x116c);
    *(undefined4 *)(param_1 + 0x1178) = 0;
    *(int *)(param_1 + 0x1174) = -iVar4;
    if (-iVar4 + iVar5 < 1) {
      iVar4 = 1;
LAB_004d246b:
      *(int *)(param_1 + 0x1174) = iVar4 - iVar5;
    }
  }
  else if (iVar5 == 1) {
    *(undefined4 *)(param_1 + 0x1174) = 0;
    *(int *)(param_1 + 0x1178) = iVar4;
    if (2 < iVar4) {
      *(int *)(param_1 + 0x1178) = 2;
    }
  }
  else if (iVar5 == 2) {
    iVar5 = *(int *)(param_1 + 0x116c);
    *(undefined4 *)(param_1 + 0x1178) = 0;
    *(int *)(param_1 + 0x1174) = iVar4;
    if (3 < iVar4 + iVar5) {
      iVar4 = 3;
      goto LAB_004d246b;
    }
  }
  else if (iVar5 == 3) {
    *(undefined4 *)(param_1 + 0x1174) = 0;
    *(int *)(param_1 + 0x1178) = -iVar4;
    if (-iVar4 < -2) {
      *(int *)(param_1 + 0x1178) = -2;
    }
  }
  SVar3 = GetKeyState(2);
  iVar5 = 1;
  iVar4 = iVar5;
  if ((-1 < SVar3) && (SVar3 = GetKeyState(1), -1 < SVar3)) {
    iVar4 = 0;
  }
  iVar6 = *(int *)(param_1 + 0x116c);
  iVar7 = 0;
  _param_2 = 0;
  if (iVar6 == 1) {
    _param_2 = 0;
    iVar5 = 4;
  }
  else if (iVar6 == 2) {
    _param_2 = 1;
  }
  else {
    iVar5 = 0;
    if (iVar6 == 3) {
      _param_2 = 4;
    }
  }
  iVar6 = *(int *)(param_1 + 0x1174);
  if (iVar6 == -2) {
    _param_2 = _param_2 + 3;
  }
  else {
    if (iVar6 != -1) {
      if (iVar6 == 1) {
        iVar5 = iVar5 + 1 + iVar4;
      }
      else if (iVar6 == 2) {
        iVar5 = iVar5 + 3 + iVar4;
      }
      goto LAB_004d253e;
    }
    _param_2 = _param_2 + 1;
  }
  _param_2 = _param_2 + iVar4;
LAB_004d253e:
  iVar2 = *(int *)(param_1 + 0x1178);
  iVar6 = 0;
  if (iVar2 == -2) {
    iVar7 = iVar4 + 3;
  }
  else if (iVar2 == -1) {
    iVar7 = iVar4 + 1;
  }
  else if (iVar2 == 1) {
    iVar6 = iVar4 + 1;
  }
  else if (iVar2 == 2) {
    iVar6 = iVar4 + 3;
  }
  FUN_005e433f(iVar5);
  FUN_005e433f(_param_2);
  FUN_005e433f(iVar7);
  FUN_005e433f(iVar6);
  return;
}

