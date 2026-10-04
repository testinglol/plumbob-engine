
void __fastcall FUN_005c61a0(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  LONG LVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  piVar1 = (int *)*param_1;
  iVar3 = param_1[2] - (int)piVar1 >> 3;
  if (iVar3 != 0) {
    uVar4 = iVar3 * 8;
    if (0x80 < uVar4) {
      FUN_00634ecc(piVar1);
      return;
    }
    LVar5 = InterlockedExchange(&DAT_006de5a4,1);
    uVar2 = DAT_006c08e8;
    if (LVar5 != 0) {
      uVar7 = 0;
      if (DAT_006c08e8 != 0) {
        uVar6 = DAT_006de5a8 >> 1;
        do {
          if (((uVar6 <= uVar7) && (DAT_006de5a4 == 0)) &&
             (LVar5 = InterlockedExchange(&DAT_006de5a4,1), LVar5 == 0)) {
            DAT_006c08e8 = 1000;
            DAT_006de5a8 = uVar7;
            goto LAB_005c62c7;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar2);
      }
      DAT_006c08e8 = 0x1e;
      iVar3 = 6;
      while( true ) {
        iVar8 = iVar3;
        if (0x1b < iVar3) {
          iVar8 = 0x1b;
        }
        LVar5 = InterlockedExchange(&DAT_006de5a4,1);
        if (LVar5 == 0) break;
        if (iVar8 < 0x15) {
          Sleep(0);
          iVar3 = iVar3 + 1;
        }
        else {
          Sleep(1 << ((char)iVar8 - 0x14U & 0x1f));
          iVar3 = iVar3 + 1;
        }
      }
    }
LAB_005c62c7:
    *piVar1 = *(int *)(&DAT_006de560 + (uVar4 + 7 >> 3) * 4);
    *(int **)(&DAT_006de560 + (uVar4 + 7 >> 3) * 4) = piVar1;
    DAT_006de5a4 = 0;
  }
  return;
}

