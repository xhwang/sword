#ifndef ASSIGN_H
#define ASSIGN_H

class CMyString {
public:
  // TODO: not use NULL
  CMyString(char* pData=nullptr);
  CMyString(const CMyString& str);
  ~CMyString(void);
  CMyString& operator=(const CMyString& str);
  char* getData();
private:
  char* m_pData;
};
#endif
