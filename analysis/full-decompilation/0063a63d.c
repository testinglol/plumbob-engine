
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0063a63d(uint param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  
  if (((DAT_00704100 <= param_1) ||
      (bVar3 = true,
      (*(byte *)((&DAT_00704000)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) == 0)) ||
     (iVar7 = FUN_00641126(), iVar7 == 0)) {
    return 0;
  }
  cVar1 = *param_2;
  if (cVar1 != 'a') {
    if (cVar1 == 'r') {
      *(undefined4 *)(iVar7 + 0xc) = 1;
      goto LAB_0063a6a3;
    }
    if (cVar1 != 'w') {
      iVar7 = 0;
      goto LAB_0063a71f;
    }
  }
  *(undefined4 *)(iVar7 + 0xc) = 2;
LAB_0063a6a3:
  *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) | DAT_00703d64;
  bVar2 = bVar3;
  bVar4 = false;
  bVar6 = false;
LAB_0063a6b3:
  bVar5 = bVar6;
  cVar1 = param_2[1];
  param_2 = param_2 + 1;
  if ((cVar1 == '\0') || (!bVar2)) goto LAB_0063a712;
  bVar6 = bVar5;
  if (cVar1 == '+') {
    if ((*(uint *)(iVar7 + 0xc) & 0x80) == 0) {
      *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfffffffc | 0x80;
      goto LAB_0063a6b3;
    }
  }
  else {
    if (cVar1 == 'b') {
LAB_0063a6f3:
      bVar6 = bVar3;
      if (bVar5) goto LAB_0063a705;
      goto LAB_0063a6b3;
    }
    if (cVar1 == 'c') {
      if (bVar4) goto LAB_0063a705;
      *(byte *)(iVar7 + 0xd) = *(byte *)(iVar7 + 0xd) | 0x40;
      bVar4 = bVar3;
      goto LAB_0063a6b3;
    }
    if (cVar1 == 'n') {
      if (bVar4) goto LAB_0063a705;
      *(byte *)(iVar7 + 0xd) = *(byte *)(iVar7 + 0xd) & 0xbf;
      bVar4 = bVar3;
      goto LAB_0063a6b3;
    }
    if (cVar1 == 't') goto LAB_0063a6f3;
  }
LAB_0063a705:
  bVar2 = false;
  bVar6 = bVar5;
  goto LAB_0063a6b3;
LAB_0063a712:
  _DAT_00703b4c = _DAT_00703b4c + 1;
  *(uint *)(iVar7 + 0x10) = param_1;
LAB_0063a71f:
  FUN_0063cf2f(iVar7);
  return iVar7;
}

