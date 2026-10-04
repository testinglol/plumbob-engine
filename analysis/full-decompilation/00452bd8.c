
bool __thiscall FUN_00452bd8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
  FUN_0044578b((int)*(short *)(param_1 + 0xf0));
  cVar2 = FUN_004749b7(*(undefined4 *)(*(int *)(param_2 + 0x11c) + 0xc),param_3,param_4);
  if (cVar2 != '\0') {
    uVar1 = *(undefined2 *)(param_2 + 0xf0);
    iVar3 = FUN_004750a6();
    *(undefined2 *)(iVar3 + 4) = uVar1;
  }
  return cVar2 != '\0';
}

