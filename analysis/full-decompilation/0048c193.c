
undefined4 __fastcall FUN_0048c193(int *param_1)

{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  
  sVar2 = FUN_0048c2bc();
  if (sVar2 != 0) {
    uVar4 = FUN_0043aeef(param_1[7]);
    iVar5 = FUN_0048c284();
    if ((iVar5 != 0) ||
       ((sVar2 = FUN_00440b6d(uVar4), sVar2 != 0 && (sVar3 = FUN_0048c2bc(), sVar2 == sVar3)))) {
      piVar6 = DAT_006e5790;
      if (*param_1 != 0) {
        for (; piVar6 != DAT_006e5794; piVar6 = piVar6 + 1) {
          if (*(int *)(*piVar6 + 8) == *param_1) {
            iVar5 = *piVar6;
            goto LAB_0048c206;
          }
        }
        iVar5 = 0;
LAB_0048c206:
        if (iVar5 != 0) {
          *(undefined1 *)(iVar5 + 0x10) = 0;
        }
      }
      cVar1 = FUN_0048c0eb();
      if (cVar1 != '\0') {
        return 1;
      }
      FUN_0048c22a();
    }
  }
  return 0;
}

