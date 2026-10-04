
void FUN_0059dce3(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  iVar1 = FUN_00457d80();
  pcVar3 = (char *)0x0;
  if (iVar1 != 0) {
    pcVar2 = (char *)FUN_004705f2((short)param_3 + 1,0xffffffff);
    if ((((pcVar2 == (char *)0x0) || (*pcVar2 != '\0')) && (pcVar3 = pcVar2, pcVar2 != (char *)0x0))
       && (*pcVar2 != '\0')) goto LAB_0059dd32;
  }
  FUN_004f70a8(param_1,param_2,iVar1,param_3);
LAB_0059dd32:
  FUN_0059dabd(param_1,pcVar3);
  return;
}

