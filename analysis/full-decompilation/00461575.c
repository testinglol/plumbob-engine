
void __thiscall FUN_00461575(undefined4 param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char local_118 [256];
  float local_18;
  float local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  pcVar5 = param_2;
  local_10 = param_1;
  do {
    for (; (*pcVar5 != '\0' && (*pcVar5 != '(')); pcVar5 = pcVar5 + 1) {
    }
    cVar3 = *pcVar5;
    iVar1 = 0;
    if (cVar3 == '\0') {
      return;
    }
    do {
      if (cVar3 == ')') break;
      cVar3 = pcVar5[iVar1 + 1];
      iVar1 = iVar1 + 1;
    } while (cVar3 != '\0');
    if (iVar1 == 0) {
      return;
    }
    if (pcVar5[iVar1] == '\0') {
      return;
    }
    uVar2 = iVar1 + 1;
    local_8 = uVar2;
    if (0 < (int)uVar2) {
      pcVar6 = pcVar5;
      pcVar7 = local_118;
      for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
    }
    local_118[iVar1 + 1] = '\0';
    iVar1 = FUN_00634d24(local_118,s___d__d__006c4660,&param_2,&local_c);
    if (iVar1 == 2) {
      local_18 = (float)(int)param_2;
      local_14 = (float)local_c;
      FUN_004614cd(&local_18);
    }
    pcVar5 = pcVar5 + local_8;
  } while( true );
}

