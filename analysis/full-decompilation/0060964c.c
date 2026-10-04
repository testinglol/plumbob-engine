
undefined4 FUN_0060964c(undefined4 *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  *param_1 = 0;
  if (param_3 == 0) {
    return 1;
  }
  bVar1 = *param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  *(byte *)(param_1 + 2) = bVar1;
  *(undefined1 *)((int)param_1 + 0xe) = 1;
  param_1[1] = (int)(char)(&DAT_006d98bc)[bVar1];
  iVar3 = (int)(char)(&DAT_006d99bc)[bVar1];
  *param_1 = 1;
  if (param_3 == 1) {
    return 1;
  }
  cVar2 = (&DAT_006d9abc)[bVar1];
  if (cVar2 == '\x01') {
    return 1;
  }
  if (cVar2 != '\x02') {
    if (('\x02' < cVar2) && (cVar2 < '\x05')) {
      return 1;
    }
    return 0;
  }
  bVar1 = param_2[1];
  param_2 = param_2 + 2;
  cVar2 = (&DAT_006d9abc)[bVar1];
  if (cVar2 != '\x05') {
    if (cVar2 == '\x06') {
      iVar3 = FUN_006097b8(bVar1,param_1,iVar3,1);
      if (param_3 == 2) {
        return 1;
      }
      bVar1 = *param_2;
      if (((&DAT_006d9abc)[bVar1] != '\a') && ((&DAT_006d9abc)[bVar1] != '\v')) {
        return 1;
      }
      goto LAB_00609729;
    }
    if (cVar2 != '\a') {
      if (cVar2 == '\b') goto LAB_00609729;
      if (cVar2 == '\t') goto LAB_00609764;
      if (cVar2 == '\n') goto LAB_00609729;
      if (cVar2 != '\v') {
        return 1;
      }
    }
    iVar3 = FUN_006097b8(bVar1,param_1,iVar3,1);
    *(undefined1 *)((int)param_1 + 0xf) = 4;
    if (param_3 == 2) {
      return 1;
    }
    bVar1 = *param_2;
    if ((&DAT_006d9abc)[bVar1] != '\n') {
      return 1;
    }
    *(undefined1 *)((int)param_1 + 0xf) = 1;
LAB_00609729:
    FUN_006097b8(bVar1,param_1,iVar3,1);
    return 1;
  }
LAB_00609764:
  if (*(char *)(param_1 + 2) == -0x53) {
    *(undefined1 *)(param_1 + 2) = 0x9f;
  }
  iVar3 = FUN_006097b8(bVar1,param_1,iVar3,1);
  if (param_3 == 2) {
    return 1;
  }
  bVar1 = *param_2;
  cVar2 = (&DAT_006d9abc)[bVar1];
  if (cVar2 != '\a') {
    if (cVar2 == '\b') goto LAB_00609729;
    if (cVar2 != '\v') {
      return 1;
    }
  }
  FUN_006097b8(bVar1,param_1,iVar3,1);
  *(undefined1 *)(param_1 + 4) = 4;
  return 1;
}

