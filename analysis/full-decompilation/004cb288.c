
void __fastcall FUN_004cb288(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  uVar2 = FUN_004e99a9();
  iVar3 = FUN_004e9744(uVar2);
  if ((*(short *)(iVar3 + 0x60e) < 2) || (DAT_006e4f18 != 0)) {
    if (*(char *)(param_1 + 0xf1) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 0xf1) = 1;
    cVar1 = FUN_004ea51f(*(undefined4 *)(param_1 + 0x10c),*(undefined4 *)(param_1 + 0x108));
    if (cVar1 != '\0') {
      pcVar4 = s_UI_queue_delete_006c7844;
      goto LAB_004cb2e3;
    }
  }
  pcVar4 = s_UI_error_006c5e80;
LAB_004cb2e3:
  FUN_0057a7f7(pcVar4,0xfffffffc);
  return;
}

