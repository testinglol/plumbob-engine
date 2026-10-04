
int FUN_0040753c(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack00000004;
  
  iVar2 = FUN_0043ac74(s_comeandsee_006c0f14);
  iVar3 = FUN_004652f7();
  iStack00000004 = 0;
  if (0 < iVar3) {
    do {
      sVar1 = FUN_00465300(iStack00000004);
      iVar6 = (int)sVar1;
      iVar4 = FUN_00407498(iVar6);
      if ((((iVar4 != 0) && (*(int *)(iVar4 + 0x11c) == iVar2)) &&
          (iVar5 = FUN_00465062(iVar6), 0 < iVar5)) && (iVar6 = FUN_0046518a(iVar6,0), 0 < iVar6)) {
        return iVar4;
      }
      iStack00000004 = iStack00000004 + 1;
    } while (iStack00000004 < iVar3);
  }
  return 0;
}

