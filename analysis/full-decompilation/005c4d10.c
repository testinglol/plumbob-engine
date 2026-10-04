
void __fastcall FUN_005c4d10(int *param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  LONG LVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = param_1[1];
  for (iVar6 = *param_1; iVar6 != iVar8; iVar6 = iVar6 + 0x48) {
    FUN_005c4d00();
  }
  piVar1 = (int *)*param_1;
  iVar8 = (param_1[2] - (int)piVar1) / 0x48;
  if (iVar8 != 0) {
    uVar3 = iVar8 * 0x48;
    if (0x80 < uVar3) {
      FUN_00634ecc(piVar1);
      return;
    }
    LVar4 = InterlockedExchange(&DAT_006de5a4,1);
    uVar2 = DAT_006c08e8;
    if (LVar4 != 0) {
      uVar7 = 0;
      if (DAT_006c08e8 != 0) {
        uVar5 = DAT_006de5a8 >> 1;
        do {
          if (((uVar5 <= uVar7) && (DAT_006de5a4 == 0)) &&
             (LVar4 = InterlockedExchange(&DAT_006de5a4,1), LVar4 == 0)) {
            DAT_006c08e8 = 1000;
            DAT_006de5a8 = uVar7;
            goto LAB_005c4e5f;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar2);
      }
      DAT_006c08e8 = 0x1e;
      iVar8 = 6;
      while( true ) {
        iVar6 = iVar8;
        if (0x1b < iVar8) {
          iVar6 = 0x1b;
        }
        LVar4 = InterlockedExchange(&DAT_006de5a4,1);
        if (LVar4 == 0) break;
        if (iVar6 < 0x15) {
          Sleep(0);
          iVar8 = iVar8 + 1;
        }
        else {
          Sleep(1 << ((char)iVar6 - 0x14U & 0x1f));
          iVar8 = iVar8 + 1;
        }
      }
    }
LAB_005c4e5f:
    *piVar1 = *(int *)(&DAT_006de560 + (uVar3 + 7 >> 3) * 4);
    *(int **)(&DAT_006de560 + (uVar3 + 7 >> 3) * 4) = piVar1;
    DAT_006de5a4 = 0;
  }
  return;
}

