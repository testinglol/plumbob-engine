
void __thiscall FUN_004d4e82(int param_1,undefined4 param_2,undefined4 param_3,byte param_4)

{
  short sVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if ((*(char *)(param_1 + 0x90) != '\0') && (*(char *)(param_1 + 0x92) == '\0')) {
    uVar3 = FUN_00584802();
    iVar4 = FUN_006359f2(uVar3,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0);
    FUN_005d98fc(*(undefined4 *)(param_1 + 0x80));
    if ((*(char *)(param_1 + 0x24) == '\0') &&
       ((cVar2 = FUN_004074f7(), iVar4 != 0 && (iVar5 = FUN_00401f6f(), iVar5 == 2)))) {
      sVar1 = *(short *)(iVar4 + 0x606);
      uVar3 = FUN_004e99a9();
      iVar5 = FUN_004e9744(uVar3);
      if ((sVar1 == *(short *)(iVar5 + 0x606)) &&
         (((*(short *)(iVar4 + 0x626) < 1 && (cVar2 == '\0')) &&
          (cVar2 = FUN_004cfb4a(iVar4), cVar2 != '\0')))) {
        *(undefined1 *)(param_1 + 0x45) = 0;
        *(undefined1 *)(param_1 + 0x44) = 0;
        *(undefined4 *)(param_1 + 4) = 2;
        return;
      }
    }
    if ((((param_4 & 1) == 0) || (*(char *)(param_1 + 0x24) != '\0')) &&
       (*(char *)(param_1 + 0x24) == '\0')) {
      *(undefined1 *)(param_1 + 0x45) = 1;
      *(undefined4 *)(param_1 + 0x4c) = param_2;
      *(undefined4 *)(param_1 + 0x50) = param_3;
      *(undefined4 *)(param_1 + 0x78) = 0;
      _memset((void *)(param_1 + 0x68),0,0x10);
    }
  }
  return;
}

