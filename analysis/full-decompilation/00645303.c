
undefined4 FUN_00645303(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  LPCWSTR lpName;
  int *piVar5;
  bool bVar6;
  
  if (((param_1 == 0) || (iVar1 = FUN_00648f11(param_1,0x3d), iVar1 == 0)) || (param_1 == iVar1))
  goto LAB_00645366;
  bVar6 = *(short *)(iVar1 + 2) == 0;
  if (DAT_00703ad8 == DAT_00703adc) {
    DAT_00703ad8 = (int *)FUN_006454f2(DAT_00703ad8);
  }
  if (DAT_00703ad8 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_00703ad0 == (undefined4 *)0x0)) {
      if (bVar6) goto LAB_0064548f;
      if (DAT_00703ad0 == (undefined4 *)0x0) {
        DAT_00703ad0 = _malloc(4);
        if (DAT_00703ad0 == (undefined4 *)0x0) goto LAB_00645366;
        *DAT_00703ad0 = 0;
        if (DAT_00703ad8 != (int *)0x0) goto LAB_006453a8;
      }
      DAT_00703ad8 = _malloc(4);
      if (DAT_00703ad8 != (int *)0x0) {
        *DAT_00703ad8 = 0;
        goto LAB_006453a8;
      }
    }
    else {
      iVar2 = FUN_00648ea9();
      if (iVar2 == 0) goto LAB_006453a8;
    }
LAB_00645366:
    uVar3 = 0xffffffff;
  }
  else {
LAB_006453a8:
    piVar4 = DAT_00703ad8;
    iVar2 = iVar1 - param_1 >> 1;
    iVar1 = FUN_00645496(param_1,iVar2);
    if ((iVar1 < 0) || (*piVar4 == 0)) {
      if (!bVar6) {
        if (iVar1 < 0) {
          iVar1 = -iVar1;
        }
        piVar4 = (int *)FUN_00640b6e(piVar4,iVar1 * 4 + 8);
        if (piVar4 != (int *)0x0) {
          piVar4[iVar1] = param_1;
          piVar4[iVar1 + 1] = 0;
          goto LAB_0064543a;
        }
        goto LAB_00645366;
      }
    }
    else {
      if (bVar6) {
        piVar5 = piVar4 + iVar1;
        FUN_00634ecc(piVar4[iVar1]);
        for (; *piVar5 != 0; piVar5 = piVar5 + 1) {
          iVar1 = iVar1 + 1;
          *piVar5 = piVar5[1];
        }
        piVar4 = (int *)FUN_00640b6e(piVar4,iVar1 << 2);
        if (piVar4 != (int *)0x0) {
LAB_0064543a:
          DAT_00703ad8 = piVar4;
        }
      }
      else {
        piVar4[iVar1] = param_1;
      }
      if (param_2 != 0) {
        iVar1 = FUN_0063ab25(param_1);
        lpName = _malloc(iVar1 * 2 + 4);
        if (lpName != (LPCWSTR)0x0) {
          FUN_00648e84(lpName,param_1);
          lpName[iVar2] = L'\0';
          SetEnvironmentVariableW(lpName,(LPCWSTR)(~-(uint)bVar6 & (uint)(lpName + iVar2 + 1)));
          FUN_00634ecc(lpName);
        }
      }
    }
LAB_0064548f:
    uVar3 = 0;
  }
  return uVar3;
}

