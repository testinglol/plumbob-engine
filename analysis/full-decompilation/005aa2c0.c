
int FUN_005aa2c0(undefined2 *param_1,char *param_2,int param_3,int param_4,ushort param_5,
                undefined4 param_6,undefined4 param_7)

{
  undefined1 *puVar1;
  char cVar2;
  undefined1 *puVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  
  *(undefined4 *)(param_1 + 4) = param_7;
  *(undefined4 *)(param_1 + 6) = param_6;
  *param_1 = 0x424d;
  param_1[1] = param_5;
  *(int *)(param_1 + 2) = param_3;
  puVar1 = (undefined1 *)(param_3 + 0x10 + (int)param_1);
  if ((param_5 & 0x200) != 0) {
    iVar6 = 0x42454e44;
    iVar7 = 4;
    puVar3 = puVar1;
    do {
      *puVar3 = (char)((uint)iVar6 >> 0x18);
      puVar3 = puVar3 + 1;
      iVar6 = iVar6 << 8;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if ((param_5 & 0x800) != 0) {
    *(undefined4 *)(puVar1 + 0xc) = 0;
  }
  pcVar5 = puVar1 + param_4;
  if ((param_2 != (char *)0x0) && ((param_5 & 0x100) != 0)) {
    iVar6 = (int)pcVar5 - (int)param_2;
    do {
      cVar2 = *param_2;
      param_2[iVar6] = cVar2;
      param_2 = param_2 + 1;
    } while (cVar2 != '\0');
    uVar4 = 0xffffffff;
    pcVar8 = pcVar5;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    pcVar5 = pcVar5 + ~uVar4;
  }
  return (int)pcVar5 - (int)param_1;
}

