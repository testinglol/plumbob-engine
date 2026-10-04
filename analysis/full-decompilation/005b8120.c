
void FUN_005b8120(byte *param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  uVar5 = 0;
  pbVar4 = param_1;
  do {
    uVar2 = 0xffffffff;
    pbVar6 = param_1;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      bVar1 = *pbVar6;
      pbVar6 = pbVar6 + 1;
    } while (bVar1 != 0);
    uVar3 = param_3 - 1U;
    if (~uVar2 - 1 < param_3 - 1U) {
      uVar2 = 0xffffffff;
      pbVar6 = param_1;
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        bVar1 = *pbVar6;
        pbVar6 = pbVar6 + 1;
      } while (bVar1 != 0);
      uVar3 = ~uVar2 - 1;
    }
    if (uVar3 < uVar5) {
      *(undefined1 *)(uVar5 + param_2) = 0;
      return;
    }
    bVar1 = *pbVar4;
    if ((bVar1 < 0x41) || (0x5a < bVar1)) {
      uVar5 = uVar5 + 1;
      pbVar4[param_2 - (int)param_1] = bVar1;
      pbVar4 = pbVar4 + 1;
    }
    else {
      uVar5 = uVar5 + 1;
      pbVar4[param_2 - (int)param_1] = bVar1 + 0x20;
      pbVar4 = pbVar4 + 1;
    }
  } while( true );
}

