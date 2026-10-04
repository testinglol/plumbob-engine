
int FUN_00618eb0(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  bool bVar8;
  
  iVar7 = 0;
  do {
    cVar1 = (&DAT_006ff848)[iVar7];
    if (((((((cVar1 != 'A') && (cVar1 != 'R')) && (cVar1 != 'G')) &&
          (((cVar1 != 'B' && (cVar1 != 'a')) &&
           ((cVar1 != 'r' && ((cVar1 != 'g' && (cVar1 != 'b')))))))) &&
         ((cVar1 != 'H' && (((cVar1 != 'S' && (cVar1 != 'L')) && (cVar1 != 'h')))))) &&
        (((cVar1 != 's' && (cVar1 != 'l')) &&
         (((cVar1 != 'Y' && ((cVar1 != 'U' && (cVar1 != 'V')))) && (cVar1 != 'y')))))) &&
       ((((cVar1 != 'u' && (cVar1 != 'v')) && (cVar1 != 'P')) && (cVar1 != 'p')))) {
LAB_00618f45:
      iVar7 = -iVar7;
      break;
    }
    iVar5 = iVar7 + -1;
    if (0 < iVar7) {
      do {
        if (cVar1 == (&DAT_006ff848)[iVar5]) goto LAB_00618f45;
        iVar5 = iVar5 + -1;
      } while (-1 < iVar5);
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xb);
  pbVar6 = &DAT_00677ab8;
  pbVar4 = &DAT_006ff848;
  do {
    bVar2 = *pbVar4;
    bVar8 = bVar2 < *pbVar6;
    if (bVar2 != *pbVar6) {
LAB_00618f7b:
      iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      goto LAB_00618f80;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar4[1];
    bVar8 = bVar2 < pbVar6[1];
    if (bVar2 != pbVar6[1]) goto LAB_00618f7b;
    pbVar4 = pbVar4 + 2;
    pbVar6 = pbVar6 + 2;
  } while (bVar2 != 0);
  iVar5 = 0;
LAB_00618f80:
  iVar3 = 4;
  if (iVar5 != 0) {
    iVar3 = iVar7;
  }
  return iVar3;
}

