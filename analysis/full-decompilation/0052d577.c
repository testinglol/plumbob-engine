
void __thiscall FUN_0052d577(int param_1,int param_2)

{
  int iVar1;
  CHAR local_44 [64];
  
  if ((*(int *)(param_1 + 0x1e8) != 0) && (param_2 != -1)) {
    iVar1 = FUN_004ea79e(param_2);
    wsprintfA(local_44,(LPCSTR)&DAT_006c08e4,(int)*(short *)(iVar1 + 0xa0));
    FUN_005d4bbf(local_44);
    (**(code **)(**(int **)(param_1 + 0x1e8) + 0x9c))(param_1 + 0x1dc);
  }
  return;
}

