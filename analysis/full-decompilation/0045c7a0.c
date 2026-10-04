
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0045c7a0(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 local_44 [29];
  byte local_27;
  undefined4 local_8;
  
  local_8 = param_1;
  if (*(int *)(param_2 + 8) != 0) {
    puVar4 = (undefined1 *)0x0;
    goto LAB_0045c8fc;
  }
  FUN_0046de64();
  FUN_0046dfa0(0,1);
  FUN_0046df67(0x3f800000,0x3f800000,0x3f800000);
  local_27 = local_27 & 0xbf;
  if ((~*(byte *)(param_3 + 6) & 2) != 0) {
    local_27 = local_27 | 0x40;
  }
  local_27 = local_27 & 0x7f;
  if ((*(byte *)(param_3 + 6) & 4) != 0) {
    local_27 = local_27 | 0x80;
  }
  iVar2 = (int)*(char *)(param_3 + 2);
  switch(iVar2) {
  case 0:
  case 2:
  case 4:
  case 6:
    break;
  case 1:
    FUN_0046df0d(0);
    iVar2 = 2;
    break;
  case 3:
    FUN_0046df0d(2);
    iVar2 = 4;
    break;
  case 5:
    FUN_0046df0d(4);
    iVar2 = 6;
    break;
  case 7:
    FUN_0046df0d(6);
    iVar2 = 0;
    break;
  case -2:
    func_0x0046df08();
    goto code_r0x0045c8b2;
  default:
    FUN_0046df0d(0);
    FUN_0046df0d(2);
    FUN_0046df0d(4);
    FUN_0046df0d(6);
    FUN_0046df67(0x3f800000,_DAT_0066740c,0x3f800000);
    goto code_r0x0045c8b2;
  }
  FUN_0046df0d(iVar2);
code_r0x0045c8b2:
  cVar1 = *(char *)(param_3 + 3);
  if (cVar1 == -2) {
    FUN_0046df34();
  }
  else if (cVar1 == -1) {
    FUN_0046df2c();
  }
  else {
    if ((cVar1 < '\0') || ('\a' < cVar1)) {
      FUN_0045451c();
      return 0;
    }
    FUN_0046df3c((int)cVar1);
  }
  puVar4 = local_44;
LAB_0045c8fc:
  uVar3 = FUN_0045aecf(param_2,puVar4);
  return uVar3;
}

