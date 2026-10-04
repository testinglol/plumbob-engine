
int __fastcall FUN_0049ceba(int param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  char cStack0000000b;
  
  cVar2 = FUN_0048d490();
  cVar3 = FUN_0048d490();
  cStack0000000b = FUN_0048d490();
  cVar4 = FUN_0048d490();
  iVar1 = *(int *)(param_1 + 0x7c);
  iVar5 = ((((int)cVar4 + (int)cStack0000000b + (int)cVar3 + (int)cVar2) / 4 + 0x80) * iVar1) /
          0x100;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  if (iVar1 <= iVar5) {
    iVar5 = iVar1 + -1;
  }
  return iVar5;
}

