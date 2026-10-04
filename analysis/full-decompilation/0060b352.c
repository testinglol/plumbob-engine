
byte __thiscall FUN_0060b352(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  char cStack00000013;
  uint local_c;
  byte local_5;
  
  local_5 = 0;
  pcVar2 = (char *)FUN_004096c2();
  uVar3 = FUN_005d49d6();
  cStack00000013 = '\0';
  if ((uVar3 != 0) && (local_c = 0, uVar3 != 0)) {
    do {
      if (*pcVar2 == '\0') {
        return local_5;
      }
      if (*pcVar2 == '&') {
        if (pcVar2[1] == '&') {
          bVar1 = FUN_0060bf16(param_2,param_3,param_4,0x26,param_2 + 0x14,0);
          local_5 = local_5 | bVar1;
          iVar4 = (**(code **)(*param_1 + 0x5c))((int)*pcVar2);
          param_3 = param_3 + iVar4;
          local_c = local_c + 1;
          pcVar2 = pcVar2 + 1;
        }
        else {
          cStack00000013 = '\x01';
        }
      }
      else {
        if (cStack00000013 == '\x01') {
          bVar1 = FUN_0060bf16(param_2,param_3,param_4,0x5f,param_2 + 0x14,0);
          local_5 = local_5 | bVar1;
        }
        bVar1 = FUN_0060bf16(param_2,param_3,param_4,(int)*pcVar2,param_2 + 0x14,0);
        local_5 = local_5 | bVar1;
        iVar4 = (**(code **)(*param_1 + 0x5c))((int)*pcVar2);
        param_3 = param_3 + iVar4;
        cStack00000013 = '\0';
      }
      pcVar2 = pcVar2 + 1;
      local_c = local_c + 1;
    } while (local_c < uVar3);
  }
  return local_5;
}

