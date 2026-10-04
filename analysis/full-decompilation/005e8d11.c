
uint __fastcall FUN_005e8d11(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  cVar1 = (**(code **)(*param_1 + 200))();
  if (cVar1 == '\0') {
    if (param_1[0x41] == 0) {
      if (param_1[0x39] == 0) {
        piVar2 = (int *)FUN_005e7743();
        iVar3 = (**(code **)(*piVar2 + 0x10))(9);
        param_1[0x39] = iVar3;
        *(undefined1 *)(param_1 + 0x3a) = 0;
        (**(code **)(*param_1 + 0x174))(1,0);
      }
      param_1[0x3b] = DAT_006fea38;
      param_1[0x3c] = DAT_006fea3c;
      param_1[0x3d] = DAT_006fea40;
      param_1[0x3e] = DAT_006fea44;
    }
    if (((param_1[0x39] != 0) || (uVar5 = param_1[0x41], uVar5 == 2)) || (uVar5 == 3)) {
      if (param_1[0x36] == 0) {
        piVar2 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
        piVar2 = (int *)(**(code **)(*piVar2 + 0x10))(1,10,0,0);
        param_1[0x36] = (int)piVar2;
        if (piVar2 != (int *)0x0) {
          iVar3 = *piVar2;
          uVar4 = FUN_005dd5e1(0xff,0xff,0xff);
          (**(code **)(iVar3 + 0x20))(uVar4);
        }
        *(undefined1 *)(param_1 + 0x38) = 0;
      }
      piVar2 = (int *)FUN_005e7743();
      iVar3 = (**(code **)(*piVar2 + 8))(1);
      param_1[0x37] = iVar3;
      uVar5 = 0;
      if (iVar3 != 0) goto LAB_005e8e09;
    }
    uVar5 = uVar5 & 0xffffff00;
  }
  else {
LAB_005e8e09:
    uVar5 = FUN_005dbf32();
  }
  return uVar5;
}

